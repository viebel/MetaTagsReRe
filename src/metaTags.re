module type Interface = {
  let description: unit => string;
  let set_description: string => unit;
  let title: unit => string;
  let set_title: string => unit;
};

type t = {
  mutable _description: string,
  mutable _title: string
};

module Make () :Interface => {
    let updateDescription: string => unit = [%bs.raw {|
        function (desc) {
            if (typeof(document) === "object" && document.querySelector) {
                document.querySelector('meta[name="description"]').setAttribute("content", desc);
            }
        }   
    |}];
    
    let updateTitle: string => unit = [%bs.raw {|
        function (title) {
            if (typeof(document) === "object" && document.querySelector) {
                document.querySelector('title').innerHTML = title;
            } 
        }   
    |}];
  let a = {_description: "", _title: ""};
  let description () => a._description;
  let set_description description => {
    updateDescription description;
    a._description = description;
  };
  let title () => {
      a._title;
  };
  let set_title title => {
    updateTitle title;
    a._title = title;
  };
};