open Jest;
open Expect;
open ReactTestingLibrary;

afterEach(cleanup);

describe("Image", () =>
  test("render and get image", () => {
    module MetaTags =
      MetaTags.Make({});
    module Image = MetaTags_Image.Make(MetaTags);
    let url = "http://my.com/aa.jpg";

    let emptyRe = [%bs.re "/^$/g"];
    <div> <Image url /> </div> |> render |> container |> expect |> JestDom.toHaveTextContentRe(emptyRe) |> ignore;

    MetaTags.image() |> expect |> toEqual(Some("http://my.com/aa.jpg"));
  })
);
