open Jest;

open ExpectJs;

describe
  "MetaTags"
  (
    fun () => {
      module MyMetaTags =
        MetaTags.Make {};
      test
        "title set and get"
        (
          fun () => {
            module MyMetaTags =
              MetaTags.Make {};
            let title = "Hello here";
            MyMetaTags.set_title title;
            expect (MyMetaTags.title ()) |> toEqual title
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
            expect (MyMetaTags.the_type ()) |> toEqual the_type
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
            expect (MyMetaTags.url ()) |> toEqual url
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
            expect (MyMetaTags.image ()) |> toEqual image
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
            expect (MyMetaTags.description ()) |> toEqual description
          }
        );
      test
        "title is empty"
        (
          fun () => {
            module MyMetaTags =
              MetaTags.Make {};
            expect (MyMetaTags.title ()) |> toEqual ""
          }
        );
      test
        "description is empty"
        (
          fun () => {
            module MyMetaTags =
              MetaTags.Make {};
            expect (MyMetaTags.description ()) |> toEqual ""
          }
        );
      test
        "url is empty"
        (
          fun () => {
            module MyMetaTags =
              MetaTags.Make {};
            expect (MyMetaTags.url ()) |> toEqual ""
          }
        );
      test
        "type is empty"
        (
          fun () => {
            module MyMetaTags =
              MetaTags.Make {};
            expect (MyMetaTags.the_type ()) |> toEqual ""
          }
        );
      test
        "image is empty"
        (
          fun () => {
            module MyMetaTags =
              MetaTags.Make {};
            expect (MyMetaTags.image ()) |> toEqual ""
          }
        )
    }
  );