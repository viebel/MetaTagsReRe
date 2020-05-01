type document;
type element;
type node;

[@bs.val] external document: document = "document";
[@bs.val] external querySelector: string => Js.Nullable.t(element) = "document.querySelector";
[@bs.val] external createElement: string => element = "document.createElement";
[@bs.send] external appendChild: (element, element) => unit = "appendChild";
[@bs.send] external setAttribute: (element, string, string) => unit = "setAttribute";
[@bs.send] external getAttribute: (element, string) => string = "setAttribute";
[@bs.send] external hasOwnProperty: ('a, string) => bool = "hasOwnProperty";
[@bs.val] external getElementsByTagName: string => array(element) = "document.getElementsByTagName";
[@bs.set] external set_innerHTML: (element, string) => unit = "innerHTML";
[@bs.set] external set_title: (document, string) => unit = "title";

let getOrCreateMeta = (key, value) => {
  let selector = "meta[" ++ key ++ "='" ++ value ++ "']";
  switch (querySelector(selector) |> Js.Nullable.toOption) {
  | Some(e) => e
  | None =>
    let meta = createElement("meta");
    setAttribute(meta, key, value);
    let head = getElementsByTagName("head")[0];
    appendChild(head, meta);
    meta;
  };
};

let createTagInHead = tagname => {
  let el = createElement(tagname);
  let head = getElementsByTagName("head")[0];
  appendChild(head, el);
  el;
};

let getOrCreateTagInHead = tagname =>
  switch (querySelector(tagname) |> Js.Nullable.toOption) {
  | Some(e) => e
  | None =>
    let el = createElement(tagname);
    let head = getElementsByTagName("head")[0];
    appendChild(head, el);
    el;
  };

let updateMetaTag = (key, content, type_) =>
  setAttribute(getOrCreateMeta(MetaTags_Metadata_Type.typeToString(type_), key), "content", content);

let updateTitle = title => set_title(document, title);

let update = (key, type_, content) =>
  switch (type_) {
  | MetaTags_Metadata_Type.Property => updateMetaTag(key, content, type_)
  | Name => updateMetaTag(key, content, type_)
  | HttpEquiv => updateMetaTag(key, content, type_)
  | Title => updateTitle(content)
  };

let updateAll = list => list |> List.iter(((k, t, c)) => update(k, t, c));
