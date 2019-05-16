let titleToTag =
  fun
  | None => ReasonReact.string("")
  | Some(title) => <title key={"title@@@" ++ title}> {ReasonReact.string(title)} </title>;

let tripleToTag = (key, type_, content) => {
  let the_key = key ++ "@" ++ MetaTags_Metadata_Type.typeToString(type_) ++ "@" ++ content;
  switch (type_) {
  | MetaTags_Metadata_Type.Property => <meta key=the_key property=key content />
  | Name => <meta key=the_key name=key content />
  | Title => <title key=the_key> {ReasonReact.string(content)} </title>
  | HttpEquiv => <meta key=the_key httpEquiv=key content />
  };
};

module Make = (MetaTags: MetaTags.Interface) => {
  [@react.component]
  let make = () => {
    let metatags = MetaTags.transformAll(tripleToTag);
    ReasonReact.array(metatags |> Array.of_list);
  };
};
