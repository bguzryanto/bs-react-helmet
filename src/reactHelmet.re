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
  "encodeSpecialCharacters": bool,
  "htmlAttributes": Js.undefined(htmlAttributes),
  "link": Js.undefined(link),
  "meta": Js.undefined(meta),
  "noscript": Js.undefined(string),
  "onChangeClientState": Js.undefined(unit),
  "style": Js.undefined(style),
  "title": Js.undefined(string),
};

let boolFromOpt = x =>
  switch (x) {
  | None => false
  | Some(x) => x
  };

[@bs.module "react-helmet"]
external helmetClass : ReasonReact.reactClass = "Helmet";

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
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=helmetClass,
    ~props={
             "base": base |> Js.Undefined.fromOption,
             "bodyAttributes": bodyAttributes |> Js.Undefined.fromOption,
             "defaultTitle": defaultTitle |> Js.Undefined.fromOption,
             "defer": defer |> Js.Undefined.fromOption,
             "encodeSpecialCharacters": encodeSpecialCharacters |> boolFromOpt,
             "htmlAttributes": htmlAttributes |> Js.Undefined.fromOption,
             "link": link |> Js.Undefined.fromOption,
             "meta": meta |> Js.Undefined.fromOption,
             "noscript": noscript |> Js.Undefined.fromOption,
             "onChangeClientState":
               onChangeClientState |> Js.Undefined.fromOption,
             "style": style |> Js.Undefined.fromOption,
             "title": title |> Js.Undefined.fromOption,
           }: t,
    children,
  );
