# @moox/bs-react-helmet

> Reason bindings to [react-helmet](https://github.com/nfl/react-helmet).

# Install

```console
yarn add react-helmet @moox/bs-react-helmet
```

Note that you need `react`, `react-dom`, `reason-react` and `react-helmet`
as peer dependencies.

Adjust your `bsconfig.js` by adding this package:

```
  "bs-dependencies": [
    "reason-react",
    "@moox/bs-react-helmet"
  ]
```

# Usage

```reason
let component = ReasonReact.statelessComponent("CommonThings");

let make = (_) => {
  ...component,
  render: _self =>
    <BsReactHelmet defaultTitle="This is a title">
      <style>
        (
          {j|
html {
  height: 100%;
  font-family: -apple-system, BlinkMacSystemFont, "Segoe UI", Roboto, Ubuntu, "Helvetica Neue", sans-serif;
}
|j}
          |> ReasonReact.string
        )
      </style>
    </BsReactHelmet>
};
```

---

## [CHANGELOG](CHANGELOG.md)

## [LICENSE](LICENSE)
