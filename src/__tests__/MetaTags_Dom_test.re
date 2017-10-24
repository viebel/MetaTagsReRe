open Jest;

open MetaTags_Dom;

open ExpectJs;

external querySelector : string => element = "document.querySelector" [@@bs.val];

external remove : element => unit = "" [@@bs.send];

external set_innerHTML : element => string => unit = "innerHTML" [@@bs.set];

external get_innerHTML : element => string = "innerHTML" [@@bs.get];
external getAttribute : element => string => string = "" [@@bs.send];
external getAttributePipe :  string => string = "getAttribute" [@@bs.send.pipe : element];


external getElementsByTagName : string => array element =
  "document.getElementsByTagName" [@@bs.val];

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

describe
  "MetaTags_Dom"
  (
    fun () => {
      let tagname = "title";
      beforeEach (fun () => cleanHead ());
      describe
        "updateTitle"
        (
          fun () => {
            test
              "when title is not defined"
              (
                fun () => {
                  let title = "foo is great";
                  updateTitle title;
                  expect (querySelector "title" |> get_innerHTML) |> toBe title
                }
              );
            test
              "when title is defined"
              (
                fun () => {
                  let title = "foo is great";
                  updateTitle "bar";
                  updateTitle title;
                  expect (querySelector "title" |> get_innerHTML) |> toBe title
                }
              )
          }
        );
      describe
        "updateDescription"
        (
          fun () => {
            test
              "when description is not defined"
              (
                fun () => {                  
                  let desc = "foo is great";
                  updateDescription desc; 
                  expect ((querySelector {|meta[name=description]|}) |> getAttributePipe  "content") |> toBe desc;
                }
              );
             test
              "when description is defined"
              (
                fun () => {
                  let desc = "foo is great";
                  updateDescription "bar";
                  updateDescription desc;
                  expect ((querySelector {|meta[name=description]|}) |> getAttributePipe "content") |> toBe desc
                }
              );
          }
        );
        describe
        "updateOgTag"
        (
          fun () => {
            test
              "when tag is not defined"
              (
                fun () => {                  
                  let desc = "foo is great";
                  updateOgTag "og:description" desc; 
                  expect ((querySelector {|meta[property="og:description"]|}) |> getAttributePipe  "content") |> toBe desc;
                }
              );
             test
              "when tag is defined"
              (
                fun () => {
                  let desc = "foo is great";
                  updateOgTag "og:description" "my desc"; 
                  updateOgTag "og:description" desc; 
                  expect ((querySelector {|meta[property="og:description"]|}) |> getAttributePipe "content") |> toBe desc
                }
              );
          }
        );
      describe
        "getOrCreateTagInHead and createTagInHead"
        (
          fun () => {
            test
              "when a tag already exists, it should retrieve it"
              (
                fun () => {
                  let previousTag = createTagInHead tagname;
                  let _ = getOrCreateTagInHead tagname;
                  let newTag = (getElementsByTagName tagname).(0);
                  expect newTag |> toEqual previousTag
                }
              );
            test
              "when a tag already exists, it should not create a new one"
              (
                fun () => {
                  let _ = createTagInHead tagname;
                  let _ = getOrCreateTagInHead tagname;
                  expect (getElementsByTagName tagname |> Array.length) |> toBe 1
                }
              );
            test
              "when a tag doesn't exist, it should create a new one"
              (
                fun () => {
                  let _ = getOrCreateTagInHead tagname;
                  expect (getElementsByTagName tagname |> Array.length) |> toEqual 1
                }
              )
          }
        )
    }
  );