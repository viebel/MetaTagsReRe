module Make = (MetaTags: MetaTags.Interface) => {
  let useUrl = url => {
    MetaTags.setUrl(url);
    React.useEffect1(
      () => {
        MetaTags.setUrl(url);
        None;
      },
      [|url|],
    );
  };

  [@react.component]
  let make = (~url, ()) => {
    useUrl(url);
    ReasonReact.null;
  };
};
