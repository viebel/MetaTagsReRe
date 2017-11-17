open Jest;

open ExpectJs;
Testutils.configure();

module Make = (MetaTags: MetaTags.Interface) => {
  let setup = (~title) => {
    module Title = MetaTags_Title.Make(MetaTags);
    Enzyme.shallow(<Title title />)
  };
};

describe(
  "Title",
  () =>
    test(
      "render and get title",
      () => {
        module MetaTags =
          MetaTags.Make(
            {}
          );
        module Context = Make(MetaTags);
        let title = "Hello title";
        let _ = Context.setup(~title);
        expect(MetaTags.title()) |> toEqual(Some(title))
      }
    )
);
