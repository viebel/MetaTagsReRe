module Make = (MetaTags: MetaTags.Interface) => {
  let component = ReasonReact.statelessComponent("Type");
  let make = (~the_type, _children) => {
    ...component,
    render: _ => {
      MetaTags.set_the_type(the_type); /* It would be better to have this side effect in `didMount` but `didMount` is not called in server side rendering. See https://github.com/reasonml/reason-react/issues/95 */
      ReasonReact.null;
    },
  };
};
