open Jest;

open MetaTags_Dom;

open ExpectJs;

Testutils.configure();

[@bs.val]
external querySelector : string => element = "document.querySelector";

[@bs.send] external remove : element => unit = "";

[@bs.set] external set_innerHTML : (element, string) => unit = "innerHTML";

[@bs.get] external get_innerHTML : element => string = "innerHTML";

[@bs.send] external getAttribute : (element, string) => string = "";

[@bs.send.pipe: element]
external getAttributePipe : string => string = "getAttribute";

[@bs.val]
external getElementsByTagName : string => array(element) =
  "document.getElementsByTagName";

type document;
[@bs.val] external document : document = "document";
[@bs.get] external documentTitle : document => string = "title";

let cleanHead: unit => unit = [%bs.raw
  {|
    function () {
        function removeIfExists(selector) {
            const elem = document.querySelector(selector);
            if(elem) {
                elem.remove();
            }
        }
        const selectorsToRemove = [
            'meta',
            'title'
        ];
        selectorsToRemove.forEach(s => removeIfExists(s));
    }
|}
];

describe("MetaTags_Dom", () => {
  beforeEach(() => cleanHead());

  describe("updateAll", () => {
    let updateAllFn = () =>
      updateAll([
        ("og:description", Property, "my og desc"),
        ("title", Title, "title"),
        ("description", Name, "my desc"),
        ("my-http", HttpEquiv, "my http equiv"),
      ]);
    test("test property", () => {
      updateAllFn();
      expect(
        querySelector({|meta[property="og:description"]|})
        |> getAttributePipe("content"),
      )
      |> toBe("my og desc");
    });
    test("test title", () => {
      updateAllFn();
      expect(documentTitle(document)) |> toBe("title");
    });
    test("test name", () => {
      updateAllFn();
      expect(
        querySelector({|meta[name="description"]|})
        |> getAttributePipe("content"),
      )
      |> toBe("my desc");
    });
    test("test http equiv", () => {
      updateAllFn();
      expect(
        querySelector({|meta[http-equiv="my-http"]|})
        |> getAttributePipe("content"),
      )
      |> toBe("my http equiv");
    });
  });

  describe("updateMetaTag", () => {
    test("when tag is not defined", () => {
      let desc = "foo is great";
      updateMetaTag("og:description", desc, Property);
      expect(
        querySelector({|meta[property="og:description"]|})
        |> getAttributePipe("content"),
      )
      |> toBe(desc);
    });
    test("when tag is defined", () => {
      let desc = "foo is great";
      updateMetaTag("og:description", "my desc", Property);
      updateMetaTag("og:description", desc, Property);
      expect(
        querySelector({|meta[property="og:description"]|})
        |> getAttributePipe("content"),
      )
      |> toBe(desc);
    });
  });
  describe("getOrCreateTagInHead and createTagInHead", () => {
    let tagname = "title";
    test("when a tag already exists, it should retrieve it", () => {
      let previousTag = createTagInHead(tagname);
      let _ = getOrCreateTagInHead(tagname);
      let newTag = getElementsByTagName(tagname)[0];
      expect(newTag) |> toEqual(previousTag);
    });
    test("when a tag already exists, it should not create a new one", () => {
      let _ = createTagInHead(tagname);
      let _ = getOrCreateTagInHead(tagname);
      expect(getElementsByTagName(tagname) |> Array.length) |> toBe(1);
    });
    test("when a tag doesn't exist, it should create a new one", () => {
      let _ = getOrCreateTagInHead(tagname);
      expect(getElementsByTagName(tagname) |> Array.length) |> toEqual(1);
    });
  });
});
