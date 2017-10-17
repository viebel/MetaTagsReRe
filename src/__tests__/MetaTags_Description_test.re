open Jest;
open ExpectJs;

let setup ::description => Enzyme.shallow <MetaTags_Description description />;

describe "Description" (fun () => {
    test "render and get description" (fun () => {
        let description = "Hello my description";
        let _ = setup ::description;
        expect (MetaTags.description ()) |> toEqual description;
    });
});
