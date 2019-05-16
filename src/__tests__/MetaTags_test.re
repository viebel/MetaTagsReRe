open Jest;

open Expect;

describe("MetaTags", () => {
  test("transformAll", () => {
    module MyMetaTags =
      MetaTags.Make({});
    let image = "Hello here";
    MyMetaTags.setImage(image);
    expect(MyMetaTags.transformAll((k, _t, c) => k ++ "@" ++ c)) |> toEqual(["og:image@Hello here"]);
  });
  test("title set and get", () => {
    module MyMetaTags =
      MetaTags.Make({});
    let title = "Hello here";
    MyMetaTags.setTitle(title);
    expect(MyMetaTags.title()) |> toEqual(Some(title));
  });
  test("type set and get", () => {
    module MyMetaTags =
      MetaTags.Make({});
    let type_ = "Hello here";
    MyMetaTags.setType(type_);
    expect(MyMetaTags.type_()) |> toEqual(Some(type_));
  });
  test("url set and get", () => {
    module MyMetaTags =
      MetaTags.Make({});
    let url = "Hello here";
    MyMetaTags.setUrl(url);
    expect(MyMetaTags.url()) |> toEqual(Some(url));
  });
  test("image set and get", () => {
    module MyMetaTags =
      MetaTags.Make({});
    let image = "Hello here";
    MyMetaTags.setImage(image);
    expect(MyMetaTags.image()) |> toEqual(Some(image));
  });
  test("description set and get", () => {
    module MyMetaTags =
      MetaTags.Make({});
    let description = "Hello here";
    MyMetaTags.setDescription(description);
    expect(MyMetaTags.description()) |> toEqual(Some(description));
  });
  test("title is empty", () => {
    module MyMetaTags =
      MetaTags.Make({});
    expect(MyMetaTags.title()) |> toBe(None);
  });
  test("description is empty", () => {
    module MyMetaTags =
      MetaTags.Make({});
    expect(MyMetaTags.description()) |> toBe(None);
  });
  test("url is empty", () => {
    module MyMetaTags =
      MetaTags.Make({});
    expect(MyMetaTags.url()) |> toBe(None);
  });
  test("type is empty", () => {
    module MyMetaTags =
      MetaTags.Make({});
    expect(MyMetaTags.type_()) |> toBe(None);
  });
  test("image is empty", () => {
    module MyMetaTags =
      MetaTags.Make({});
    expect(MyMetaTags.image()) |> toBe(None);
  });
  test("add subscriber", () => {
    module MyMetaTags =
      MetaTags.Make({});
    let isCalled = ref(false);
    MyMetaTags.addSubscriber(() => isCalled := true);
    MyMetaTags.setMetadata("title", "My title", Title);

    expect(isCalled^) |> toBe(true);
  });
});
