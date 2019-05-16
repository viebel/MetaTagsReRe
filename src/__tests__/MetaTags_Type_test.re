open Jest;
open Expect;
open ReactTestingLibrary;

afterEach(cleanup);

describe("Type", () =>
  test("render and get type", () => {
    module MetaTags =
      MetaTags.Make({});
    module Type = MetaTags_Type.Make(MetaTags);
    let type_ = "article";

    let emptyRe = [%bs.re "/^$/g"];
    <div> <Type type_ /> </div> |> render |> container |> expect |> JestDom.toHaveTextContentRe(emptyRe) |> ignore;

    MetaTags.type_() |> expect |> toEqual(Some(type_));
  })
);
