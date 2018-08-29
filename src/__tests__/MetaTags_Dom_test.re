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
            'meta[property="og:title"]',
            'meta[name="description"]',
            'title'
        ];
        selectorsToRemove.forEach(s => removeIfExists(s));
    }
|}
];

describe("MetaTags_Dom", () => {
  let tagname = "title";
  beforeEach(() => cleanHead());
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
