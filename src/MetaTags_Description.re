module Make = (MetaTags: MetaTags.Interface) => {
  let setDescription = description =>
    switch (description) {
    | None => ()
    | Some(description) => MetaTags.setDescription(description)
    };

  let useDescription = description => {
    setDescription(description);
    React.useEffect1(
      () => {
        setDescription(description);
        None;
      },
      [|description|],
    );
  };

  [@react.component]
  let make = (~description=?, ()) => {
    useDescription(description);
    ReasonReact.null;
  };
};
