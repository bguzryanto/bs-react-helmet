type script;

type style;

type htmlAttributes;

type bodyAttributes;

type titleAttributes;

type link;

type meta;

type base;

type t = {
  .
  "defer": bool,
  "encodeSpecialCharacters": bool,
  "onChangeClientState": Js.undefined(unit),
  "htmlAttributes": Js.undefined(htmlAttributes),
  "bodyAttributes": Js.undefined(bodyAttributes),
  "titleAttributes": Js.undefined(titleAttributes),
  "titleTemplate": Js.undefined(string),
  "defaultTitle": Js.undefined(string),
  /* some <head> tags can be passed as props */
  "title": Js.undefined(string),
  "meta": Js.undefined(meta),
  "base": Js.undefined(string),
  "link": Js.undefined(link),
  "style": Js.undefined(style),
  "script": Js.undefined(string),
  "noscript": Js.undefined(string),
};

let boolFromOpt = x =>
  switch (x) {
  | None => false
  | Some(x) => x
  };

[@bs.module "react-helmet"]
external helmetClass: ReasonReact.reactClass = "Helmet";

let make =
    (
      ~defer=?,
      ~encodeSpecialCharacters=?,
      ~onChangeClientState=?,
      ~htmlAttributes=?,
      ~bodyAttributes=?,
      ~titleAttributes=?,
      ~defaultTitle=?,
      ~titleTemplate=?,
      ~title=?,
      ~meta=?,
      ~base=?,
      ~link=?,
      ~style=?,
      ~script=?,
      ~noscript=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=helmetClass,
    ~props={
             "defer": defer |> boolFromOpt,
             "encodeSpecialCharacters": encodeSpecialCharacters |> boolFromOpt,
             "onChangeClientState":
               onChangeClientState |> Js.Undefined.fromOption,
             "htmlAttributes": htmlAttributes |> Js.Undefined.fromOption,
             "bodyAttributes": bodyAttributes |> Js.Undefined.fromOption,
             "titleAttributes": titleAttributes |> Js.Undefined.fromOption,
             "titleTemplate": titleTemplate |> Js.Undefined.fromOption,
             "defaultTitle": defaultTitle |> Js.Undefined.fromOption,

             "title": title |> Js.Undefined.fromOption,
             "meta": meta |> Js.Undefined.fromOption,
             "base": base |> Js.Undefined.fromOption,

             "link": link |> Js.Undefined.fromOption,
             "style": style |> Js.Undefined.fromOption,
             "script": script |> Js.Undefined.fromOption,
             "noscript": noscript |> Js.Undefined.fromOption,
           }: t,
    children,
  );