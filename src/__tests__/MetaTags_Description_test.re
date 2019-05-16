open Jest;
open Expect;
open ReactTestingLibrary;

afterEach(cleanup);

describe("Description", () =>
  test("render and get description", () => {
    module MetaTags =
      MetaTags.Make({});
    module Description = MetaTags_Description.Make(MetaTags);
    let description = "Hello description";

    let emptyRe = [%bs.re "/^$/g"];
    <div> <Description description /> </div>
    |> render
    |> container
    |> expect
    |> JestDom.toHaveTextContentRe(emptyRe)
    |> ignore;

    MetaTags.description() |> expect |> toEqual(Some(description));
  })
);
