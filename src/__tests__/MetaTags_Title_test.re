open Jest;
open ExpectJs;

let setup ::title => Enzyme.shallow <MetaTags_Title title />;

describe "Description" (fun () => {
    test "render and get title" (fun () => {
        let title = "Hello my title";
        let _ = setup ::title;
        expect (MetaTags.title ()) |> toEqual title;
    });
});
