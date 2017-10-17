module type Interface = {
  let set_title: string => unit;
  let title: unit => string;
  let set_description: string => unit;
  let description: unit => string;
};

type t = {
  mutable _description: string,
  mutable _title: string
};

module Make () :Interface => {
   let updateDescription: string => unit = [%bs.raw
    {|
    function (desc) {
        if (typeof(document) === "object" && document.querySelector) {
            var description = document.querySelector('meta[name="description"]');
            if (description) {
              description.setAttribute("content", desc);
            } else {
              var meta = document.createElement('meta');
              meta.setAttribute('name', 'description');
              meta.setAttribute('content', desc);
              document.getElementsByTagName('head')[0].appendChild(meta);
            }
        }
    }
    |}
  ];

  let updateOgTag: string => string => unit = [%bs.raw
  {|
    function (property, content) {
      if (typeof(document) === "object" && document.querySelector) {
          var tag = document.querySelector(`meta[property="${property}"]`);
          if (tag) {
            tag.setAttribute('content', content);
          } else {
            var meta = document.createElement('meta');
      meta.setAttribute('property', property);
            meta.setAttribute('content', content);
            document.getElementsByTagName('head')[0].appendChild(meta);
          }
      }
  }
  |}];
  let updateTitle: string => unit = [%bs.raw
    {|
    function (title) {
        if (typeof(document) === "object" && document.querySelector) {
            var title = document.querySelector('title');
            if (title) {
               title.innerHTML = title;
            }
        }
    }
|}
  ];
  let a = {_description: "", _title: ""};
  let description () => a._description;
  let set_description description => {
    updateDescription description;
    updateOgTag "og:description" description;
    a._description = description
  };
  let title () => a._title;
  let set_title title => {
    updateTitle title;
    a._title = title
  };
};