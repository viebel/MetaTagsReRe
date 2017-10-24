module type Interface = {
  let set_title: string => unit;
  let title: unit => string;
  let set_url: string => unit;
  let url: unit => string;
  let set_image: string => unit;
  let image: unit => string;
  let set_description: string => unit;
  let description: unit => string;
  let set_the_type: string => unit;
  let the_type: unit => string;
};

type t = {
  mutable _description: string,
  mutable _type: string,
  mutable _url: string,
  mutable _image: string,
  mutable _title: string
};

module Make () :Interface => {
  module Dom = MetaTags_Dom;
  let a = {_description: "", _title: "", _type: "", _url: "", _image: ""};
  let description () => a._description;
  let set_description description => {
    Dom.updateDescription description; 
    Dom.updateOgTag "og:description" description;
    a._description = description
  };
  let set_the_type the_type => {
    Dom.updateOgTag "og:type" the_type;
    a._type = the_type;
  };
  let the_type () => a._type;
  let title () => a._title;
  let set_title title => {
    Dom.updateTitle title;
    Dom.updateOgTag "og:title" title;    
    a._title = title
  };
  let url () => a._url;
  let set_url url => {
    Dom.updateOgTag "og:url" url;    
    a._url = url
  };
  let image () => a._image;
  let set_image image => {
    Dom.updateOgTag "og:image" image;    
    a._image = image
  };
};  