open Jest;
open ExpectJs;

describe "MetaTags" (fun () => {
    test "title set and get" (fun () => {
        let title = "Hello here";
        MetaTags.set_title title;
        expect (MetaTags.title ()) |> toEqual title;
    });
    test "description set and get" (fun () => {
        let description = "Hello here";
        MetaTags.set_description description;
        expect (MetaTags.description ()) |> toEqual description;
    });
});
