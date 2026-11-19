/* Copyright (c) 2024 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "chrome/browser/ui/webui/top_chrome/webui_contents_wrapper.h"

#include <utility>

#include "chrome/browser/ui/browser_tabstrip.h"
#include "chrome/browser/ui/browser_window/public/browser_window_interface.h"

#include <chrome/browser/ui/webui/top_chrome/webui_contents_wrapper.cc>
<<<<<<< HEAD
#undef AddNewContents

void WebUIContentsWrapper::SetWebContentsAddNewContentsBrowser(
    base::WeakPtr<BrowserWindowInterface> browser) {
  browser_ = std::move(browser);
}

void WebUIContentsWrapper::CloseTrackedPopups() {
  for (auto& web_contents : tracked_popups_) {
    if (web_contents) {
      web_contents->Close();
    }
  }
  tracked_popups_.clear();
}

content::WebContents* WebUIContentsWrapper::Host::AddNewContents(
    content::WebContents* source,
    std::unique_ptr<content::WebContents> new_contents,
    const GURL& target_url,
    ui::mojom::WindowOpenDisposition disposition,
    const blink::mojom::WindowFeatures& window_features,
    bool user_gesture,
    bool* was_blocked) {
  return WebUIContentsWrapper::Host::AddNewContents_ChromiumImpl(
      source, std::move(new_contents), target_url, disposition, window_features,
      user_gesture, was_blocked);
}

content::WebContents* WebUIContentsWrapper::AddNewContents(
    content::WebContents* source,
    std::unique_ptr<content::WebContents> new_contents,
    const GURL& target_url,
    ui::mojom::WindowOpenDisposition disposition,
    const blink::mojom::WindowFeatures& window_features,
    bool user_gesture,
    bool* was_blocked) {
  if (!browser_) {
    return host_ ? host_->AddNewContents(
                       source, std::move(new_contents), target_url, disposition,
                       window_features, user_gesture, was_blocked)
                 : nullptr;
  }
  auto* contents = chrome::AddWebContents(
      browser_.get(), source, std::move(new_contents), target_url,
      ui::mojom::WindowOpenDisposition::kNewPopup, window_features,
      NavigateParams::WindowAction::kShowWindow, user_gesture);
  if (!contents) {
    return nullptr;
  }
  tracked_popups_.push_back(contents->GetWeakPtr());
  return contents;
}
=======
>>>>>>> 20f9266e7f4 ([wallet] Replace WebUIContentsWrapper popup macros with plaster)
