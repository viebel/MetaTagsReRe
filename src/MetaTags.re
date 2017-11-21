module Dom = MetaTags_Dom;

module Pairs = {
  type t = (string, Dom.metadata_type);
  let compare = ((x0, _y0), (x1, _y1)) => Pervasives.compare(x0, x1);
};

module PairsMap = Map.Make(Pairs);

type t = {mutable map: PairsMap.t(string)};

module type Interface = {
  let transform_all: ((string, MetaTags_Dom.metadata_type, string) => 'a) => array('a);
  let set_metadata: (string, string, MetaTags_Dom.metadata_type) => unit;
  let get_metadata: (string, MetaTags_Dom.metadata_type) => option(string);
  let set_title: string => unit;
  let title: unit => option(string);
  let set_url: string => unit;
  let url: unit => option(string);
  let set_image: string => unit;
  let image: unit => option(string);
  let set_description: string => unit;
  let description: unit => option(string);
  let set_the_type: string => unit;
  let the_type: unit => option(string);
};

module Make = (()) : Interface => {
  let a = {map: PairsMap.empty};
  let transform_all = (f) =>
    PairsMap.bindings(a.map)
    |> List.map((((key, _type), content)) => f(key, _type, content))
    |> Array.of_list;
  let set_metadata = (key, content, _type) => {
    a.map = PairsMap.add((key, _type), content, a.map);
    Dom.updateMetaTag(key, content, _type)
  };
  let get_metadata = (key, _type) =>
    switch (PairsMap.find((key, _type), a.map)) {
    | item => Some(item)
    | exception Not_found => None
    };
  let description = () => get_metadata("description", Name);
  let set_description = (description) => {
    set_metadata("description", description, Name);
    set_metadata("og:description", description, Property)
  };
  let set_the_type = (the_type) => set_metadata("og:type", the_type, Property);
  let the_type = () => get_metadata("og:type", Property);
  let title = () => get_metadata("og:title", Property);
  let set_title = (title) => {
    Dom.updateTitle(title);
    set_metadata("", title, Title);
    set_metadata("og:title", title, Property)
  };
  let url = () => get_metadata("og:url", Property);
  let set_url = (url) => set_metadata("og:url", url, Property);
  let image = () => get_metadata("og:image", Property);
  let set_image = (image) => set_metadata("og:image", image, Property);
};
