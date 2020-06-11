let helmet = BsReactHelmet.renderStatic();

let title: string = helmet##title##toString();

[@react.component]
let make = () => {
  helmet##meta##toComponent();
};
