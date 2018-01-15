/***
 * Represents a function taking express request and response to output a promise for some graphqlOptions
 */
type expressGraphQLOptionsFunction('rootValue, 'context, 'response) =
  (Express.Request.t, Express.Response.t) =>
  Js.Promise.t(
    ApolloServerCore.graphqlOptions('rootValue, 'context, 'response)
  );


/***
 * Represents a function taking express request to output a promise for some GraphiQL data
 */
type expressGraphiQLOptionsFunction('variables) =
  Express.Request.t => Js.Promise.t(ApolloServerCore.graphiqlData('variables));


/***
 * Calls the graphqlExpress middleware creation with static options
 */
[@bs.module "apollo-server-express"]
external graphqlExpress :
  ApolloServerCore.graphqlOptions('rootValue, 'context, 'response) =>
  Express.Middleware.t =
  "graphqlExpress";


/***
 * Calls the graphqlExpress middleware creation with function options
 */
[@bs.module "apollo-server-express"]
external graphqlExpressAsync :
  expressGraphQLOptionsFunction('rootValue, 'context, 'response) =>
  Express.Middleware.t =
  "graphqlExpress";


/***
 * Calls the graphiqlExpress middleware creation with static options
 */
[@bs.module "apollo-server-express"]
external graphiqlExpress :
  ApolloServerCore.graphiqlData('variables) => Express.Middleware.t =
  "graphiqlExpress";


/***
 * Calls the graphiqlExpress middleware creation with function options
 */
[@bs.module "apollo-server-express"]
external graphiqlExpressAsync :
  expressGraphiQLOptionsFunction('variables) => Express.Middleware.t =
  "graphiqlExpress";


/***
 * Usability wrapper around the static graphqlExpress function
 */
let createGraphQLExpressMiddleware =
    (
      ~formatError=?,
      ~rootValue=?,
      ~context=?,
      ~logFunction=?,
      ~formatParams=?,
      ~validationRules=?,
      ~formatResponse=?,
      ~fieldResolver=?,
      ~debug=?,
      schema
    ) =>
  graphqlExpress({
    "schema": schema,
    "formatError": Js.Null_undefined.from_opt(formatError),
    "rootValue": Js.Null_undefined.from_opt(rootValue),
    "context": Js.Null_undefined.from_opt(context),
    "logFunction": Js.Null_undefined.from_opt(logFunction),
    "formatParams": Js.Null_undefined.from_opt(formatParams),
    "validationRules": Js.Null_undefined.from_opt(validationRules),
    "formatResponse": Js.Null_undefined.from_opt(formatResponse),
    "fieldResolver": Js.Null_undefined.from_opt(fieldResolver),
    "debug": Js.Null_undefined.from_opt(debug)
  });


/***
 * Usability wrapper around the static graphiqlExpress function
 */
let createGraphiQLExpressMiddleware =
    (~query=?, ~variables=?, ~operationName=?, ~result=?, endpointURL) =>
  graphiqlExpress({
    "endpointURL": endpointURL,
    "query": Js.Null_undefined.from_opt(query),
    "variables": Js.Null_undefined.from_opt(variables),
    "operationName": Js.Null_undefined.from_opt(operationName),
    "result": Js.Null_undefined.from_opt(result)
  });