# MetaTagsReRe
Meta tags reason react components.
It works both in client side and server side rendering



# Usage
```
module MetaTags = MetaTags.Make ();
moudule Title = MetaTags_Title.Make MetaTags;
<Title title="awesome article" />
```

```
module MetaTags = MetaTags.Make ();
moudule Description = MetaTags_Description.Make MetaTags;
<Description description="awesome article about reason react meta tags" />
```

# Browser

On the browser do not forget to update the dom

```
module MetaTags = MetaTags.Make ();
/*...*/
MetaTags.addSubscriber(() => MetaTags.Dom.updateAll(MetaTags.getAll()));
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


