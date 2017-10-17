module Make (MetaTags: MetaTags.Interface) => {
    let component = ReasonReact.statelessComponent "MetaTags";
    let make _children => {
      ...component,
      render: fun _ => {
        <div>
            <title> (ReasonReact.stringToElement (MetaTags.title ())) </title>
            <meta name="description" content=(MetaTags.description ()) />
            <meta property="og:description" content=(MetaTags.description ()) />        
        </div>
      }
    };
};