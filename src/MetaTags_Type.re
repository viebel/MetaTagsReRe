module Make = (MetaTags: MetaTags.Interface) => {
  let component = ReasonReact.statelessComponent("Type");
  let make = (~type_, _children) => {
    ...component,
    render: _ => {
      MetaTags.setType(type_); /* It would be better to have this side effect in `didMount` but `didMount` is not called in server side rendering. See https://github.com/reasonml/reason-react/issues/95 */
      ReasonReact.null;
    },
  };
};
