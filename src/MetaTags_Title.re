module Make = (MetaTags: MetaTags.Interface) => {
  let setTitle = title =>
    switch (title) {
    | None => ()
    | Some(title) => MetaTags.setTitle(title)
    };

  let useTitle = title => {
    setTitle(title);
    React.useEffect1(
      () => {
        setTitle(title);
        None;
      },
      [|title|],
    );
  };

  [@react.component]
  let make = (~title=?, ()) => {
    useTitle(title);
    ReasonReact.null;
  };
};
