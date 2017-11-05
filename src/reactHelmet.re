type script;

type style;

type htmlAttributes;

type bodyAttributes;

type link;

type meta;

type base;

type t = {
  .
  "base": Js.undefined(string),
  "bodyAttributes": Js.undefined(bodyAttributes),
  "defaultTitle": Js.undefined(string),
  "defer": Js.undefined(string),
  "encodeSpecialCharacters": Js.boolean,
  "htmlAttributes": Js.undefined(htmlAttributes),
  "link": Js.undefined(link),
  "meta": Js.undefined(meta),
  "noscript": Js.undefined(string),
  "onChangeClientState": Js.undefined(unit),
  "style": Js.undefined(style),
  "title": Js.undefined(string)
};

let boolFromOpt = (x) =>
  switch x {
  | None => Js.false_
  | Some(x) => Js.Boolean.to_js_boolean(x)
  };

[@bs.module "react-helmet"] external helmetClass : ReasonReact.reactClass = "Helmet";

let make =
    (
      ~base=?,
      ~bodyAttributes=?,
      ~defaultTitle=?,
      ~defer=?,
      ~encodeSpecialCharacters=?,
      ~htmlAttributes=?,
      ~link=?,
      ~meta=?,
      ~noscript=?,
      ~onChangeClientState=?,
      ~style=?,
      ~title=?,
      children
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=helmetClass,
    ~props={
             "base": base |> Js.Undefined.from_opt,
             "bodyAttributes": bodyAttributes |> Js.Undefined.from_opt,
             "defaultTitle": defaultTitle |> Js.Undefined.from_opt,
             "defer": defer |> Js.Undefined.from_opt,
             "encodeSpecialCharacters": encodeSpecialCharacters |> boolFromOpt,
             "htmlAttributes": htmlAttributes |> Js.Undefined.from_opt,
             "link": link |> Js.Undefined.from_opt,
             "meta": meta |> Js.Undefined.from_opt,
             "noscript": noscript |> Js.Undefined.from_opt,
             "onChangeClientState": onChangeClientState |> Js.Undefined.from_opt,
             "style": style |> Js.Undefined.from_opt,
             "title": title |> Js.Undefined.from_opt
           }: t,
    children
  );
