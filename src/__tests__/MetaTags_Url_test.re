open Jest;

open ExpectJs;

module Make (MetaTags: MetaTags.Interface) => {
  let setup ::url => {
    module Url = MetaTags_Url.Make MetaTags;
    Enzyme.shallow <Url url />
  };
};

describe
  "Url"
  (
    fun () =>
      test
        "render and get url"
        (
          fun () => {
            module MetaTags = MetaTags.Make ();
            module Context = Make MetaTags;
            let url = "http://my.com/aa.jpg";
            let _ = Context.setup ::url;
            expect (MetaTags.url ()) |> toEqual url
          }
        )
  );