open Jest;
open ExpectJs;

describe "MetaTags" (fun () => {
    test "title set and get" (fun () => {
        module MetaTags = MetaTags.Make ();
        let title = "Hello here";
        MetaTags.set_title title;
        expect (MetaTags.title ()) |> toEqual title;
    });
    test "description set and get" (fun () => {
        module MetaTags = MetaTags.Make ();        
        let description = "Hello here";
        MetaTags.set_description description;
        expect (MetaTags.description ()) |> toEqual description;
    });
    test "title and description are empty" (fun () => {
        module MetaTags = MetaTags.Make ();
        expect (MetaTags.title ()) |> toEqual "";
    });
});
