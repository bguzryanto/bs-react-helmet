let component = ReasonReact.statelessComponent("BsReactHelmetTest");

let make = _ => {
  ...component,
  render: _self =>
    <BsReactHelmet defaultTitle="This is a title">
      <style>
        {
          {j|
html {
  height: 100%;
  font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, Ubuntu, "Helvetica Neue", sans-serif;
}
|j}
          |> ReasonReact.string
        }
      </style>
    </BsReactHelmet>,
};