open Jest;

open ExpectJs;

describe
  "MetaTags"
  (
    fun () => {
        test
        "transform_all"
        (
          fun () => {
            module MyMetaTags =
              MetaTags.Make {};
            let image = "Hello here";
            MyMetaTags.set_image image;
            expect (MyMetaTags.transform_all (fun k _t c => k ^ "@" ^ c)) |> toEqual [|"og:image@Hello here"|]
          }
        );
      test
        "title set and get"
        (
          fun () => {
            module MyMetaTags =
              MetaTags.Make {};
            let title = "Hello here";
            MyMetaTags.set_title title;
            expect (MyMetaTags.title ()) |> toEqual (Some title)
          }
        );
      test
        "type set and get"
        (
          fun () => {
            module MyMetaTags =
              MetaTags.Make {};
            let the_type = "Hello here";
            MyMetaTags.set_the_type the_type;
            expect (MyMetaTags.the_type ()) |> toEqual (Some the_type)
          }
        );
      test
        "url set and get"
        (
          fun () => {
            module MyMetaTags =
              MetaTags.Make {};
            let url = "Hello here";
            MyMetaTags.set_url url;
            expect (MyMetaTags.url ()) |> toEqual (Some url)
          }
        );
      test
        "image set and get"
        (
          fun () => {
            module MyMetaTags =
              MetaTags.Make {};
            let image = "Hello here";
            MyMetaTags.set_image image;
            expect (MyMetaTags.image ()) |> toEqual (Some image)
          }
        );
      test
        "description set and get"
        (
          fun () => {
            module MyMetaTags =
              MetaTags.Make {};
            let description = "Hello here";
            MyMetaTags.set_description description;
            expect (MyMetaTags.description ()) |> toEqual (Some description)
          }
        );
      test
        "title is empty"
        (
          fun () => {
            module MyMetaTags =
              MetaTags.Make {};
            expect (MyMetaTags.title ()) |> toBe None
          }
        );
      test
        "description is empty"
        (
          fun () => {
            module MyMetaTags =
              MetaTags.Make {};
            expect (MyMetaTags.description ()) |> toBe None
          }
        );
      test
        "url is empty"
        (
          fun () => {
            module MyMetaTags =
              MetaTags.Make {};
            expect (MyMetaTags.url ()) |> toBe None
          }
        );
      test
        "type is empty"
        (
          fun () => {
            module MyMetaTags =
              MetaTags.Make {};
            expect (MyMetaTags.the_type ()) |> toBe None
          }
        );
      test
        "image is empty"
        (
          fun () => {
            module MyMetaTags =
              MetaTags.Make {};
            expect (MyMetaTags.image ()) |> toBe None 
          }
        )
    }
  );