module Make (MetaTags: MetaTags.Interface) => {
    let component = ReasonReact.statelessComponent "Image";
    let make ::url _children => {
      ...component,
      render: fun _ => {
        MetaTags.set_image url; /* It would be better to have this side effect in `didMount` but `didMount` is not called in server side rendering. See https://github.com/reasonml/reason-react/issues/95 */
        <div />
      }
    };
  };  