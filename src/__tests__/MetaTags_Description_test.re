open Jest;

open ExpectJs;
Testutils.configure();

module Make = (MetaTags: MetaTags.Interface) => {
  let setup = (~description) => {
    module Description = MetaTags_Description.Make(MetaTags);
    Enzyme.shallow(<Description description />);
  };
};

describe("Description", () =>
  test("render and get description", () => {
    module MetaTags =
      MetaTags.Make({});
    module Context = Make(MetaTags);
    let description = "Hello description";
    let _ = Context.setup(~description);
    expect(MetaTags.description()) |> toEqual(Some(description));
  })
);
