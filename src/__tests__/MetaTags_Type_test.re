open Jest;

open ExpectJs;
Testutils.configure();

module Make = (MetaTags: MetaTags.Interface) => {
  let setup = (~type_) => {
    module Type = MetaTags_Type.Make(MetaTags);
    Enzyme.shallow(<Type type_ />);
  };
};

describe("Type", () =>
  test("render and get type", () => {
    module MetaTags =
      MetaTags.Make({});
    module Context = Make(MetaTags);
    let type_ = "article";
    let _ = Context.setup(~type_);
    expect(MetaTags.type_()) |> toEqual(Some(type_));
  })
);
