open Jest;

open ExpectJs;
Testutils.configure();

module Make = (MetaTags: MetaTags.Interface) => {
  let setup = () => {
    module MetaTags = MetaTags_MetaTags.Make(MetaTags);
    Testutils.mount(<MetaTags />);
  };
};

let listItems = wrapper => wrapper |> Enzyme.children;

describe("MetaTagsMetaTags", () =>
  test("render when only title is defined", () => {
    let title = "my title";
    module MetaTags =
      MetaTags.Make({});
    MetaTags.setTitle(title);
    MetaTags.setDescription("desc");
    module Context = Make(MetaTags);
    let wrapper = Context.setup();
    let expectedNode = <title> (ReasonReact.string(title)) </title>;
    expect(Enzyme.contains(expectedNode, wrapper)) |> toBe(true);
  })
);
