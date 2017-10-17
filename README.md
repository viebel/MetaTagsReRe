# MetaTagsReRe
Meta tags reason react components.
It works both in client side and server side rendering



# Usage
```
<Title title="awesome article" />
```

```
<Description description="awesome article about reason react meta tags" />
```

# Server side rendering

Somewhere you need to add the static meta tags for description and title.
You can retrieve the description value with `MetaTags.description()` and the title value with `MetaTags.title()`

# Internals

For client side rendering, the components update the corresponding meta tag with javascript code.
For server side rendering, the components update some value in `MetaTags` module. This value can be retrieved from anywhere.


# Contributing

## Run tests
```
yarn test
```

or watch with:
```
yarn test:watch
```
