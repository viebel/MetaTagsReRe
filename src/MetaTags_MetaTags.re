
let descriptionToTag = fun 
    | None => ReasonReact.stringToElement ""
    | Some description =>  (ReasonReact.arrayToElement [|
                             <meta key="1" name="description" content=description />, 
                             <meta key="2" property="og:description" content=description />
                             |]);
    

module Make (MetaTags: MetaTags.Interface) => {
    let component = ReasonReact.statelessComponent "MetaTags";
    let make _children => {
      ...component,
      render: fun _ => {        
        <div>
            <title> (ReasonReact.stringToElement (MetaTags.title ())) </title>
            (descriptionToTag (MetaTags.description ()))
            <meta property="og:title" content=(MetaTags.title ()) />  
            <meta property="og:type" content=(MetaTags.the_type ()) />        
            <meta property="og:image" content=(MetaTags.image ()) />      
            <meta property="og:url" content=(MetaTags.url ()) />        
        </div>
      }
    };
};  