module Dom = MetaTags_Dom;

type metadata = MetaTags_Metadata_Type.t;

module Pairs = {
  type t = (string, metadata);
  let compare = ((x0, _y0), (x1, _y1)) => Pervasives.compare(x0, x1);
};

module PairsMap = Map.Make(Pairs);

type t = {mutable map: PairsMap.t(string)};

type subscriber = unit => unit;

module type Interface = {
  let addSubscriber: subscriber => unit;
  let getAll: unit => list((string, metadata, string));
  let transformAll: ((string, metadata, string) => 'a) => list('a);
  let setMetadata: (string, string, metadata) => unit;
  let getMetadata: (string, metadata) => option(string);
  let setTitle: string => unit;
  let title: unit => option(string);
  let setUrl: string => unit;
  let url: unit => option(string);
  let setImage: string => unit;
  let image: unit => option(string);
  let setDescription: string => unit;
  let description: unit => option(string);
  let setType: string => unit;
  let type_: unit => option(string);
};

module Make = (()) : Interface => {
  let subscribers: ref(list(subscriber)) = ref([]);
  let fire = () => subscribers^ |> List.iter(subscriber => subscriber());
  let addSubscriber = subscriber => subscribers := [subscriber, ...subscribers^];

  let a = {map: PairsMap.empty};

  let getAll = () => a.map |> PairsMap.bindings |> List.map((((k, t), c)) => (k, t, c));

  let transformAll = f => getAll() |> List.map(((k, t, c)) => f(k, t, c));

  let setMetadata = (key, content, _type) => {
    a.map = PairsMap.add((key, _type), content, a.map);
    fire();
  };
  let getMetadata = (key, _type) =>
    switch (PairsMap.find((key, _type), a.map)) {
    | item => Some(item)
    | exception Not_found => None
    };
  let description = () => getMetadata("description", Name);
  let setDescription = description => {
    setMetadata("description", description, Name);
    setMetadata("og:description", description, Property);
  };
  let setType = type_ => setMetadata("og:type", type_, Property);
  let type_ = () => getMetadata("og:type", Property);
  let title = () => getMetadata("og:title", Property);
  let setTitle = title => {
    setMetadata("", title, Title);
    setMetadata("og:title", title, Property);
  };
  let url = () => getMetadata("og:url", Property);
  let setUrl = url => setMetadata("og:url", url, Property);
  let image = () => getMetadata("og:image", Property);
  let setImage = image => setMetadata("og:image", image, Property);
};
