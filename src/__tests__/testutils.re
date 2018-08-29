/* This is a workaround unit mount in added to bs-enzyme (as mount should really return a deepWrapper)*/
[@bs.module "enzyme"]
external mount : Enzyme.node => Enzyme.shallowWrapper = "";
let configure = () => Enzyme.configureEnzyme(Enzyme.react_16_adapter());
