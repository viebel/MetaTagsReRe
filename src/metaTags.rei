module type Interface = {
    let description: unit => string;
    let set_description: string => unit;
    let title: unit => string;
    let set_title: string => unit;
  };
