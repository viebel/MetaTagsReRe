open Jest;

open ExpectJs;

module Make (MetaTags: MetaTags.Interface) => {
  let setup () => {
    module MetaTags = MetaTags_MetaTags.Make MetaTags;
    Enzyme.shallow <MetaTags />
  };
};

let listItems wrapper => wrapper |> Enzyme.children;

describe
  "MetaTagsMetaTags"
  (
    fun () => {
      test
        "render when description and title are defined"
        (
          fun () => {
            let description = "my description";
            let title = "my title";
            module MetaTags = MetaTags.Make ();
            MetaTags.set_description description;
            MetaTags.set_title title;
            module Context = Make MetaTags;
            let children = Context.setup () |> listItems;
            expect (Enzyme.length children) |> toEqual 7;
          }
        ); 
        test
        "render when title is defined"
        (
          fun () => {
            let title = "my title";
            module MetaTags = MetaTags.Make ();
            MetaTags.set_title title;
            module Context = Make MetaTags;
            let children = Context.setup () |> listItems;
            expect (Enzyme.length children) |> toEqual 5;
          }
        );
        }
       
  );