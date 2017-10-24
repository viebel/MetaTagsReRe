open Jest;

open ExpectJs;

module Make (MetaTags: MetaTags.Interface) => {
  let setup ::url => {
    module Image = MetaTags_Image.Make MetaTags;
    Enzyme.shallow <Image url />
  };
};

describe
  "Image"
  (
    fun () =>
      test
        "render and get image"
        (
          fun () => {
            module MetaTags = MetaTags.Make ();
            module Context = Make MetaTags;
            let url = "http://my.com/aa.jpg";
            let _ = Context.setup ::url;
            expect (MetaTags.image ()) |> toEqual url
          }
        )
  );