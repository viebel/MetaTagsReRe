module Make = (MetaTags: MetaTags.Interface) => {
  let useImage = url => {
    MetaTags.setImage(url);
    React.useEffect1(
      () => {
        MetaTags.setImage(url);
        None;
      },
      [|url|],
    );
  };

  [@react.component]
  let make = (~url, ()) => {
    useImage(url);
    ReasonReact.null;
  };
};
