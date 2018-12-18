type htmlAttributes;

type bodyAttributes;

type titleAttributes;

type meta;

type base;

type link;

type style;

type script;

type noscript;

[@bs.deriving abstract]
type jsProps = {
  defer: Js.undefined(bool),
  encodeSpecialCharacters: Js.undefined(bool),
  onChangeClientState: Js.undefined(unit),
  htmlAttributes: Js.undefined(htmlAttributes),
  bodyAttributes: Js.undefined(bodyAttributes),
  titleAttributes: Js.undefined(titleAttributes),
  titleTemplate: Js.undefined(string),
  defaultTitle: Js.undefined(string),
  /* some <head> tags can be passed as props */
  title: Js.undefined(string),
  meta: Js.undefined(meta),
  base: Js.undefined(string),
  link: Js.undefined(link),
  style: Js.undefined(style),
  script: Js.undefined(script),
  noscript: Js.undefined(noscript),
};

let objectWithoutUndefinedValues: 'a => 'a = [%bs.raw
  "function(obj) {
    const newObj = {};
    Object.keys(obj).map(function(k) {
      if (obj[k] !== undefined) {
        newObj[k] = obj[k]
      }
    });
    return newObj;
  }"
];

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
    ~props=
      objectWithoutUndefinedValues(
        jsProps(
          ~defer=defer->Js.Undefined.fromOption,
          ~encodeSpecialCharacters=
            encodeSpecialCharacters->Js.Undefined.fromOption,
          ~onChangeClientState=onChangeClientState->Js.Undefined.fromOption,
          ~htmlAttributes=htmlAttributes->Js.Undefined.fromOption,
          ~bodyAttributes=bodyAttributes->Js.Undefined.fromOption,
          ~titleAttributes=titleAttributes->Js.Undefined.fromOption,
          ~titleTemplate=titleTemplate->Js.Undefined.fromOption,
          ~defaultTitle=defaultTitle->Js.Undefined.fromOption,
          ~title=title->Js.Undefined.fromOption,
          ~meta=meta->Js.Undefined.fromOption,
          ~base=base->Js.Undefined.fromOption,
          ~link=link->Js.Undefined.fromOption,
          ~style=style->Js.Undefined.fromOption,
          ~script=script->Js.Undefined.fromOption,
          ~noscript=noscript->Js.Undefined.fromOption,
        ),
      ),
    children,
  );