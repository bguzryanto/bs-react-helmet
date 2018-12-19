[@bs.module "react-helmet"]
external helmetClass: ReasonReact.reactClass = "Helmet";

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
  [@bs.optional]
  defer: bool,
  [@bs.optional]
  encodeSpecialCharacters: bool,
  [@bs.optional]
  onChangeClientState: unit,
  [@bs.optional]
  htmlAttributes,
  [@bs.optional]
  bodyAttributes,
  [@bs.optional]
  titleAttributes,
  [@bs.optional]
  titleTemplate: string,
  [@bs.optional]
  defaultTitle: string,
  /* some <head> tags can be passed as props */
  [@bs.optional]
  title: string,
  [@bs.optional]
  meta,
  [@bs.optional]
  base: string,
  [@bs.optional]
  link,
  [@bs.optional]
  style,
  [@bs.optional]
  script,
  [@bs.optional]
  noscript,
};

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
      jsProps(
        ~defer?,
        ~encodeSpecialCharacters?,
        ~onChangeClientState?,
        ~htmlAttributes?,
        ~bodyAttributes?,
        ~titleAttributes?,
        ~titleTemplate?,
        ~defaultTitle?,
        ~title?,
        ~meta?,
        ~base?,
        ~link?,
        ~style?,
        ~script?,
        ~noscript?,
        (),
      ),
    children,
  );