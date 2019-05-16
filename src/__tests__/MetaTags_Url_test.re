open Jest;
open Expect;
open ReactTestingLibrary;

afterEach(cleanup);

describe("Url", () =>
  test("render and get url", () => {
    module MetaTags =
      MetaTags.Make({});
    module Url = MetaTags_Url.Make(MetaTags);
    let url1 = "http://my.com/aa1.jpg";
    let url2 = "http://my.com/aa2.jpg";

    let emptyRe = [%bs.re "/^$/g"];
    let rendered = <div> <Url url=url1 /> </div> |> render;

    rendered |> container |> expect |> JestDom.toHaveTextContentRe(emptyRe) |> ignore;
    MetaTags.url() |> expect |> toEqual(Some(url1)) |> ignore;

    rendered |> rerender(<div> <Url url=url2 /> </div>);
    rendered |> container |> expect |> JestDom.toHaveTextContentRe(emptyRe) |> ignore;
    MetaTags.url() |> expect |> toEqual(Some(url2));
  })
);
