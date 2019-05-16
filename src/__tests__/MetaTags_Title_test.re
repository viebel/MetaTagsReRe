open Jest;
open Expect;
open ReactTestingLibrary;

afterEach(cleanup);

describe("Title", () =>
  test("render and get title", () => {
    module MetaTags =
      MetaTags.Make({});
    module Title = MetaTags_Title.Make(MetaTags);
    let title = "Hello title";

    let emptyRe = [%bs.re "/^$/g"];
    <div> <Title title /> </div> |> render |> container |> expect |> JestDom.toHaveTextContentRe(emptyRe) |> ignore;

    MetaTags.title() |> expect |> toEqual(Some(title));
  })
);
