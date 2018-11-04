type t =
  | HttpEquiv
  | Name
  | Property
  | Title;

let typeToString =
  fun
  | HttpEquiv => "http-equiv"
  | Property => "property"
  | Name => "name"
  | Title => "title";
