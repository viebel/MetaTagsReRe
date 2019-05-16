open Jest;
open Expect;
open ReactTestingLibrary;

afterEach(cleanup);

describe("MetaTagsMetaTags", () =>
  test("render when title is defined", () => {
    module MetaTags =
      MetaTags.Make({});
    module MetaTagsDom = MetaTags_MetaTags.Make(MetaTags);
    MetaTags.setTitle("my title");
    MetaTags.setDescription("my desc");

    <MetaTagsDom /> |> render |> container |> expect |> JestDom.toContainHTML({j|<title>my title</title>|j});
  })
);
