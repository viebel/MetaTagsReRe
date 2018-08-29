let titleToTag =
  fun
  | None => ReasonReact.string("")
  | Some(title) =>
    <title key=("title@@@" ++ title)> (ReasonReact.string(title)) </title>;

module Dom = MetaTags_Dom;

let tripleToTag = (key, the_type, content) => {
  let the_key =
    key ++ "@" ++ Dom.metadata_typeToString(the_type) ++ "@" ++ content;
  switch (the_type) {
  | Dom.Property => <meta key=the_key property=key content />
  | Dom.Name => <meta key=the_key name=key content />
  | Dom.HttpEquiv => <meta key=the_key httpEquiv=key content />
  | Dom.Title => <title key=the_key> (ReasonReact.string(content)) </title>
  };
};

module Make = (MetaTags: MetaTags.Interface) => {
  let component = ReasonReact.statelessComponent("MetaTags");
  let make = _children => {
    ...component,
    render: _ => {
      let metatags = MetaTags.transform_all(tripleToTag);
      ReasonReact.array(metatags);
    },
  };
};
