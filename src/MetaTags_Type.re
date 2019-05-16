module Make = (MetaTags: MetaTags.Interface) => {
  let useType = type_ => {
    MetaTags.setType(type_);
    React.useEffect1(
      () => {
        MetaTags.setType(type_);
        None;
      },
      [|type_|],
    );
  };

  [@react.component]
  let make = (~type_, ()) => {
    useType(type_);
    ReasonReact.null;
  };
};
