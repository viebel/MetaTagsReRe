open Jest;

open ExpectJs;

Testutils.configure();


module Make = (MetaTags: MetaTags.Interface) => {
  let setup = (~url) => {
    module Image = MetaTags_Image.Make(MetaTags);
    Enzyme.shallow(<Image url />)
  };
};

describe(
  "Image",
  () =>
    test(
      "render and get image",
      () => {
        module MetaTags =
          MetaTags.Make(
            {}
          );
        module Context = Make(MetaTags);
        let url = "http://my.com/aa.jpg";
        let _ = Context.setup(~url);
        expect(MetaTags.image()) |> toEqual(Some(url))
      }
    )
);
