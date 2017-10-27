type metadata_type = | HttpEquiv | Name | Property | Title;
  
type document;

type element;

external document : document = "" [@@bs.val];

external querySelector : string => element = "document.querySelector" [@@bs.val];

external createElement : string => element = "document.createElement" [@@bs.val];

external appendChild : element => element => unit = "" [@@bs.send];

external setAttribute : element => string => string => unit = "" [@@bs.send];
external getAttribute : element => string => string = "" [@@bs.send];


external hasOwnProperty : 'a => string => bool = "" [@@bs.send];

external getElementsByTagName : string => array element =
  "document.getElementsByTagName" [@@bs.val];

external set_innerHTML : element => string => unit = "innerHTML" [@@bs.set];

external set_title : document => string => unit = "title" [@@bs.set];

  

let elementExists: string => bool = [%bs.raw
  {|
    function(selector) {
        return document.querySelector(selector) !== null;
    }
|}
];

let clientSide: unit => bool = [%bs.raw
  {|
  function () {
    return (typeof(document) === "object" && document.querySelector);
  }
|}
];

let getOrCreateMeta key value => {
  let selector = "meta[" ^ key ^ "='" ^ value ^ "']";
  if (elementExists selector) {
    querySelector selector;
  } else {
    let meta = createElement "meta";
    setAttribute meta key value;
    let head = (getElementsByTagName "head").(0);
    appendChild head meta;    
    meta
  }
};

let createTagInHead tagname => {
  let el = createElement tagname;
  let head = (getElementsByTagName "head").(0);
  appendChild head el;
  el
};

let getOrCreateTagInHead tagname  => {
  if (elementExists tagname) {
    querySelector tagname;
  } else {
    let el = createElement tagname;
    let head = (getElementsByTagName "head").(0);
    appendChild head el;
    el
  }
};

let updateDescription desc =>
  if (clientSide ()) {
    setAttribute (getOrCreateMeta "name" "description") "content" desc
  };

let metadata_typeToString = fun
| HttpEquiv => "http-equiv"
| Property => "property"
| Name => "name"
| Title => "title";

let updateMetaTag key content _type => {
  if (clientSide ()) {
    setAttribute (getOrCreateMeta (metadata_typeToString _type) key) "content" content;
  };
};
  
let updateOgTag property content => 
  if (clientSide ()) {
    setAttribute (getOrCreateMeta "property" property) "content" content;
  };
let updateTitle title =>
  if (clientSide ()) {
    set_title document title;
  };


